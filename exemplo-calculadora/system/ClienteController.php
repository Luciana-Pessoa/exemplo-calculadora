<?php

require_once("Cliente.php");

class ClienteController {
    private $cliente;

    public function __construct($pdo) {
        $this->cliente = new Cliente($pdo);
    }

    public function salvar_cliente($name, $razao_social, $cnpj, $logradouro, $numero, $bairro, $cidade, $estado) {
        return $this->cliente->salvar($name, $razao_social, $cnpj, $logradouro, $numero, $bairro, $cidade, $estado);
    }

    public function editar_cliente($id, $name, $razao_social, $cnpj, $logradouro, $numero, $bairro, $cidade, $estado) {
        return $this->cliente->editar($id, $name, $razao_social, $cnpj, $logradouro, $numero, $bairro, $cidade, $estado);
    }

    public function exibir_clientes() {
        $clientes = $this->cliente->exibirClientes();
        error_log(print_r($clientes, true)); // Adiciona log para verificar os dados retornados
        return $clientes;
    }
}
?>
