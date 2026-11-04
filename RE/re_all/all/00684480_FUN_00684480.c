
void FUN_00684480(int *param_1)

{
  switch(param_1[10]) {
  case 0:
    FUN_00684500(param_1,0);
    return;
  case 1:
    FUN_00684500(param_1,1);
    return;
  case 2:
  case 3:
    FUN_00684500(param_1,3);
    return;
  case 4:
    FUN_00684500(param_1,4);
    return;
  case 5:
    FUN_00684500(param_1,5);
    return;
  default:
    *(undefined4 *)(*param_1 + 0x14) = 10;
    (**(code **)*param_1)(param_1);
    return;
  }
}

