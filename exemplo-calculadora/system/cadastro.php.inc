<?php  
require_once ("./includes/xajax/xajax.inc.php");
require_once ("Conexao.php");
require_once ("Cliente.php");
require_once ("ClienteController.php");

$xajax = new xajax("", "xajax_", 'ISO-8859-1');

function salvar($name, $razaoSocial, $cnpj, $logradouro, $numero, $bairro, $cidade, $estado) {
    $response = new xajaxResponse('ISO-8859-1');
    $conexao = new Conexao();
    $clienteController = new ClienteController($conexao->getPdo());

    if ($clienteController->salvar_cliente($name, $razaoSocial, $cnpj, $logradouro, $numero, $bairro, $cidade, $estado)) {
        resultado($name, $razaoSocial, $cnpj, $logradouro, $numero, $bairro, $cidade, $estado, $response);
    } else {
        $response->addAlert("Erro ao salvar os dados do cliente.");
    }
    $response->addRedirect("https://minas/xajax/luciana/exemplo-calculadora/clientes_cadastrados.php");
    return $response;
}

function exibirClientes() {
    $conexao = new Conexao();
    $clienteController = new ClienteController($conexao->getPdo());
    $clientes = $clienteController->exibir_clientes();

    

    // Escapando os caracteres especiais para o XML
    foreach ($clientes as &$cliente) {
        $cliente['nome_fantasia'] = htmlspecialchars($cliente['nome_fantasia'], ENT_QUOTES, 'UTF-8');
        $cliente['razao_social'] = htmlspecialchars($cliente['razao_social'], ENT_QUOTES, 'UTF-8');
        $cliente['cnpj'] = htmlspecialchars($cliente['cnpj'], ENT_QUOTES, 'UTF-8');
    }

    $objResponse = new xajaxResponse('ISO-8859-1');
    $objResponse->addScriptCall('atualizarTabelaClientes', $clientes); // Chama a função JavaScript para atualizar a tabela de clientes
    return $objResponse;
}

function resultado($name, $razaoSocial, $cnpj, $logradouro, $numero, $bairro, $cidade, $estado, $response) {
    $response->addScript("$('#res-cadastrado').removeClass('visually-hidden');");
    $response->addScript("$('#res-name').html(`$name`);");
    $response->addScript("$('#res-razaoSocial').html(`$razaoSocial`);");
    $response->addScript("$('#res-cnpj').html(`$cnpj`);");
    $response->addScript("$('#res-logradouro').html(`$logradouro`);");
    $response->addScript("$('#res-numero').html(`$numero`);");
    $response->addScript("$('#res-bairro').html(`$bairro`);");
    $response->addScript("$('#res-cidade').html(`$cidade`);");
    $response->addScript("$('#res-estado').html(`$estado`);");
}

$xajax->registerFunction("salvar");
$xajax->registerFunction("exibirClientes");

$xajax->processRequests();
?>