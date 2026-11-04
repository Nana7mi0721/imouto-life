
undefined4 FUN_00657d70(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_2 + 8) != 1) || (*(int *)(param_2 + 0xc) != 0)) {
    return 1;
  }
  switch(*(undefined2 *)(param_2 + 2)) {
  case 4:
  case 0xd:
    FUN_00655790(param_1,param_2,&param_1);
    *param_3 = param_1;
    param_3[1] = 0;
    return 0;
  default:
    return 2;
  case 0x10:
  case 0x12:
    uVar1 = FUN_006557c0(param_1,param_2,param_3);
    return uVar1;
  }
}

