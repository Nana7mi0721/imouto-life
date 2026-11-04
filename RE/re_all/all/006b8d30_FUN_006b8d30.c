
int FUN_006b8d30(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_4;
  
  if ((((param_1 == (int *)0x0) || (*param_1 == 0)) ||
      (iVar1 = *(int *)(*param_1 + 0x3c), iVar1 == 0)) || (iVar1 = *(int *)(iVar1 + 8), iVar1 == 0))
  {
    iVar1 = -1;
  }
  else {
    iVar1 = FUN_006bc560(iVar1,&local_30);
    if (-1 < iVar1) {
      *param_2 = local_30;
      param_2[1] = local_2c;
      param_2[2] = local_28;
      param_2[3] = local_20;
      param_2[4] = local_1c;
      param_2[5] = local_18;
      param_2[6] = local_24;
      param_2[7] = local_14;
      param_2[8] = local_4;
      return iVar1;
    }
  }
  return iVar1;
}

