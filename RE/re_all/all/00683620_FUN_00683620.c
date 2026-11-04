
int FUN_00683620(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  switch(param_1[5]) {
  case 200:
    (**(code **)(param_1[0x6a] + 4))(param_1);
    (**(code **)(param_1[6] + 8))(param_1);
    param_1[5] = 0xc9;
  case 0xc9:
    iVar1 = (**(code **)param_1[0x6a])(param_1);
    if (iVar1 == 1) {
      FUN_006836e0(param_1);
      param_1[5] = 0xca;
      return 1;
    }
    break;
  case 0xca:
    return 1;
  case 0xcb:
  case 0xcc:
  case 0xcd:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd2:
    iVar1 = (**(code **)param_1[0x6a])(param_1);
    return iVar1;
  default:
    *(undefined4 *)(*param_1 + 0x14) = 0x15;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  return iVar1;
}

