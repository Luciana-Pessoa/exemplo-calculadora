$(document).ready(function () {
  $(document).on("click", "#btn-calcular", function () {
    calcular();
  });

  $(document).on("click", ".btn-selecionar-operador", function () {
    $(".btn-selecionar-operador").removeClass("btn-operador-selecionado");
    $(this).addClass("btn-operador-selecionado");

    $("#operacao").val($(this).val());
    limparResultadoCalculo();
  });
});

function limparResultadoCalculo() {
  $("#resultado").html("");
}

function calcular() {
  const num1 = $("#num1").val();
  const num2 = $("#num2").val();
  const operacao = $("#operacao").val();
  xajax_calcular(operacao, num1, num2);
}

function exibirResultadoCalculo(resultado) {
  $("#resultado").html(resultado);
}
