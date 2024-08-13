<?php
require_once("./includes/xajax/xajax.inc.php");
$xajax = new xajax("", "xajax_", 'ISO-8859-1');

function calcular($operacao, $num1, $num2)
{
    $response = new xajaxResponse('ISO-8859-1');
    switch ($operacao) {
        case 1:
            $resultado = somar($num1, $num2);
            break;
        case 2:
            $resultado = subtrair($num1, $num2);
            break;
        case 3:
            $resultado = multiplicar($num1, $num2);
            break;
        case 4:
            $resultado = dividir($num1, $num2);
            break;
    }

    resultado($resultado, $response);
    return $response->getXML();
}

function resultado($resultado, $response)
{
    $response->addScript("$('#resultado').html(`$resultado`);");
    // $response->addScript("exibirResultadoCalculo(`$resultado`);");
    // $response->addScriptCall("exibirResultadoCalculo", $resultado);
}

function somar($num1, $num2)
{
    return $num1 + $num2;
}

function subtrair($num1, $num2)
{
    return $num1 - $num2;
}


function multiplicar($num1, $num2)
{
    return $num1 * $num2;
}

function dividir($num1, $num2)
{
    if ($num1 <= 0) {
        return 0;
    }
    return $num1 / $num2;
}

$xajax->registerFunction("calcular");
$xajax->registerFunction("somar");
$xajax->registerFunction("subtrair");
$xajax->registerFunction("multiplicar");
$xajax->registerFunction("dividir");
$xajax->registerFunction("resultado");
$xajax->processRequests();
