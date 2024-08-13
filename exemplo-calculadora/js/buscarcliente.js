$(document).ready(function () {
  $(document).on("click", "#btn-buscar-cnpj", function () {
      buscarClienteCnpj();
  });

  $(document).on("click", "#btn-buscar-nome", function () {
      buscarClienteNome();
  });

  $(document).on("click", "#btn-buscar-editar-cliente", function () {
      buscarEditarCliente();
  });
});

function limparResultadoCliente() {
  $("#resultado").html("");
}

function buscarClienteCnpj() {
  const cnpj = $("#cnpj").val().trim();
  if (cnpj === "") {
      alert("O campo CNPJ é obrigatório.");
      return;
  }
  xajax_buscarClienteCnpj(cnpj);
}

function buscarClienteNome() {
  const nome = $("#nome").val().trim();
  if (nome === "") {
      alert("O campo Nome é obrigatório.");
      return;
  }
  xajax_buscarClienteNome(nome);
}

function buscarEditarCliente() {
  var myid = $("#res-id").html().trim();
  if (myid && !isNaN(myid)) {
      var url = "editarcliente.php?id=" + myid;
      window.location = url;
  } else {
      alert("ID do cliente não encontrado.");
  }
}

function exibirCliente(resultado) {  // Função para exibir o cliente
  if (resultado === "") {
      alert("Cliente não encontrado.");
      $("#resultado").html("<p>Cliente não encontrado.</p>");
  } else {
      $("#resultado").html(resultado);
  }
}
