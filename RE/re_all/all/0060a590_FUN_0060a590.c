
undefined4 FUN_0060a590(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  if (param_3 == (int *)0x0) {
    return 0x80070057;
  }
  *param_3 = 0;
  iVar1 = FUN_0056d3d0(param_2,&DAT_0085f364,0x10);
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 4))(param_1);
    *param_3 = (int)param_1;
    return 0;
  }
  iVar1 = FUN_0056d3d0(param_2,&DAT_0085f374,0x10);
  if (iVar1 == 0) {
    (**(code **)(*(int *)param_1[0xc] + 4))((int *)param_1[0xc]);
    *param_3 = param_1[0xc];
    return 0;
  }
  return 0x80004002;
}

