
int FUN_00657260(undefined4 param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(int *)(param_2 + 8) != 1) || (*(int *)(param_2 + 0xc) != 0)) {
    return 1;
  }
  switch(*(undefined2 *)(param_2 + 2)) {
  case 1:
    FUN_00655750(param_1,param_2,param_3);
    return 0;
  default:
    iVar1 = 2;
    break;
  case 3:
    FUN_00655760(param_1,param_2,&param_1);
    iVar1 = FUN_00659f30(param_1);
    if (iVar1 == 0) {
      *param_3 = (undefined1)param_1;
      return 0;
    }
    break;
  case 4:
    FUN_00655790(param_1,param_2,&param_1);
    iVar1 = FUN_00659f60(param_1);
    if (iVar1 == 0) {
      *param_3 = (undefined1)param_1;
      return 0;
    }
    break;
  case 6:
    FUN_00655750(param_1,param_2,&param_1);
    iVar1 = FUN_0065a220(param_1);
    if (iVar1 == 0) {
      *param_3 = (undefined1)param_1;
      return 0;
    }
    break;
  case 8:
    FUN_00655760(param_1,param_2,&param_1);
    iVar1 = FUN_00659f40(param_1);
    if (iVar1 == 0) {
      *param_3 = (undefined1)param_1;
      return 0;
    }
    break;
  case 9:
    FUN_00655790(param_1,param_2,&param_1);
    iVar1 = FUN_00659f80(param_1);
    if (iVar1 == 0) {
      *param_3 = (undefined1)param_1;
      return 0;
    }
    break;
  case 0x10:
    iVar1 = FUN_006557c0(param_1,param_2,&local_8);
    if ((iVar1 == 0) && (iVar1 = FUN_00659fa0(local_8,local_4), iVar1 == 0)) {
      *param_3 = (undefined1)local_8;
      return 0;
    }
    break;
  case 0x11:
    iVar1 = FUN_006557c0(param_1,param_2,&local_8);
    if ((iVar1 == 0) && (iVar1 = FUN_00659fc0(local_8,local_4), iVar1 == 0)) {
      *param_3 = (undefined1)local_8;
      return 0;
    }
  }
  return iVar1;
}

