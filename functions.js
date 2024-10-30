function change_color() {
  var paraR = document.getElementById("paragraph_R").value;
  var paraG = document.getElementById("paragraph_G").value;
  var paraB = document.getElementById("paragraph_B").value;
  var borderWidth = document.getElementById("border_width").value;
  var backR = document.getElementById("backR").value;
  var backG = document.getElementById("backG").value;
  var backB = document.getElementById("backB").value;

  var tag = document.getElementById("paragraph");
  tag.style.borderColor = `rgb(${paraR},${paraG},${paraB})`;
  //document.getElementById("paragraph").style.borderWidth = "200px";
  tag.style.borderWidth = `${borderWidth}px`; 
  tag.style.backgroundColor = `rgb(${backR},${backG},${backB})`;
  
}

function checkPass()
{
  var p1 = document.getElementById("pass1").value;
  var p2 = document.getElementById("pass2").value;
  if ((p1.length<8) || (p2.length<8))
  {
    alert("passwords have to be at least 8 characters")
  }
  else if (p1!=p2)
  {
    alert("passwords dont match")
  }
  else if (p1==p2)
  {
    alert("passwords match and at least 8 characters")
  }
  else
  alert("hmmmm smth went wrong")
    //x = document.getElementById("myForm").length;
}
