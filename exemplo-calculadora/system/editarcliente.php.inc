<?php
require_once ("./includes/xajax/xajax.inc.php");
require_once ("Conexao.php");
require_once ("Cliente.php");

$xajax = new xajax("", "xajax_", 'ISO-8859-1');

function preCliente() {
    $id = $_GET['id'];
    

    if ($id) {
        $response = new xajaxResponse('ISO-8859-1');
        $conexao = new Conexao();
        $cliente = new Cliente($conexao->getPdo());

        $result = $cliente->buscarPorId($id);
        

        if ($result) {
            $response->addAssign('name', 'value', $result['nome_fantasia']);
            $response->addAssign('razao_social', 'value', $result['razao_social']);
            $response->addAssign('cnpj', 'value', $result['cnpj']);
            $response->addAssign('logradouro', 'value', $result['logradouro']);
            $response->addAssign('numero', 'value', $result['numero']);
            $response->addAssign('bairro', 'value', $result['bairro']);
            $response->addAssign('cidade', 'value', $result['cidade']);
            $response->addAssign('estado', 'value', $result['estado']);

            
        }
        else {
            $response->addScriptCall("redirecionarListagem");
        }

        return $response->getXML();
    }
}

function editarCliente(
    $name, $razaoSocial, $cnpj, $logradouro, $numero, $bairro, $cidade, $estado) {
    $id = $_GET['id'];

    if ($id) {
        $response = new xajaxResponse('ISO-8859-1');
        $conexao = new Conexao();
        $cliente = new Cliente($conexao->getPdo());

        $result = $cliente->editar(
            $id,$name,$razaoSocial,$cnpj,$logradouro,$numero,$bairro,$cidade, $estado);
            
        if ($result) {
            resultado("Dados editados com sucesso!", $response);
        } else {
            resultado("Erro ao editar os dados.", $response);
        }

        return $response->getXML();
    }
}

function resultado($mensagem, $response) {
    $response->addScript("$('#res-editou').html(`$mensagem`);");
}

$xajax->registerFunction("editarCliente");
$xajax->registerFunction("preCliente");
$xajax->registerFunction("resultado");

$xajax->processRequests();
?>
