<?php

include("system/index.php.inc");
$xajax->printJavascript("./includes/xajax/");
?>
<!DOCTYPE html>
<html lang="pt-BR">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./css/index.css">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" />
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.7.1/jquery.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>

    <title>Calculadora online</title>
</head>

<body>
    <main>
        <form action="">
            <div id="resultado-container">
                Resultado: <span id="resultado"></span>
            </div>
            <div id="numeros">
                <input type="numeros" name="num3" class="input-numeros" id="num1">
                <input type="numeros" name="num4" class="input-numeros" id="num2">
                <input type="hidden" name="operacao" id="operacao">
            </div>
            <div id="operadores-container">
                <button class="btn-operadores btn-selecionar-operador" data-type="adicao" type="button" value="1">
                    <img class="operadores" src="./assets/plus.svg">
                </button>
                <button class="btn-operadores btn-selecionar-operador" data-type="subtracao" type="button" value="2">
                    <img class="operadores" src="./assets/minus.svg">
                </button>
                <button class="btn-operadores btn-selecionar-operador" data-type="multiplicacao" type="button" value="3">
                    <img class="operadores" src="./assets/multiplus.svg">
                </button>
                <button class="btn-operadores btn-selecionar-operador" data-type="divisao" type="button" value="4">
                    <img class="operadores" src="./assets/divider.svg">
                </button>
                <button class="btn-operadores" id="btn-calcular" type="button">
                    <img class="operadores" src="./assets/equals.svg">
                </button>
            </div>
        </form>
    </main>
    <script src="./js/scripts.js"></script>
</body>

</html>