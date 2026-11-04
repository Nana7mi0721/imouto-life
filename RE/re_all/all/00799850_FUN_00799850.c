
undefined4 FUN_00799850(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = param_1[1];
  iVar2 = *param_1;
  switch(param_2) {
  case 0xfa9:
    if (param_3 != (int *)0x0) {
      *param_3 = param_1[0xc];
      return 0;
    }
    break;
  default:
    return 0xfffffffb;
  case 0xfbc:
    piVar4 = param_1 + 0xb;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar4 = 0;
      piVar4 = piVar4 + 1;
    }
    FUN_007a1d70(iVar2 + (int)param_1,0xfbc);
    FUN_00799c30(iVar1 + (int)param_1);
    param_1[0xb] = param_1[2];
    param_1[0xf] = param_1[3] / 400;
    return 0;
  case 0xfbd:
    if (param_3 != (int *)0x0) {
      *param_3 = param_1[3];
      return 0;
    }
    break;
  case 0xfbf:
    if (param_3 != (int *)0x0) {
      *param_3 = param_1[0x14];
      return 0;
    }
    break;
  case 0xfc1:
    if (param_3 != (int *)0x0) {
      if (param_1[0xe] == 0x3ea) {
        FUN_007a1d70(iVar2 + (int)param_1,0xfc1,param_3);
        return 0;
      }
      *param_3 = param_1[9];
      return 0;
    }
    break;
  case 0xfc2:
    if ((-0x8001 < (int)param_3) && ((int)param_3 < 0x8000)) {
      param_1[10] = (int)param_3;
      return 0;
    }
    break;
  case 0xfc7:
    if (param_3 != (int *)0x0) {
      *param_3 = param_1[0x11];
      return 0;
    }
    break;
  case 0xfcd:
    if (param_3 != (int *)0x0) {
      *param_3 = param_1[10];
      return 0;
    }
  }
  return 0xffffffff;
}

