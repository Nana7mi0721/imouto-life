
undefined4 FUN_0052f110(int param_1)

{
  int *piVar1;
  int local_10;
  undefined4 local_c;
  int local_8;
  undefined4 local_4;
  
  if (*(int *)(param_1 + 0x93614) != 0) {
    *(undefined4 *)(param_1 + 0x93614) = 0;
    piVar1 = (int *)(param_1 + 0x93618);
    FUN_00523da0(param_1 + 0x931bc,0,piVar1,*piVar1,*(undefined4 *)(param_1 + 0x9361c),
                 *(undefined4 *)(param_1 + 0x931b0),DAT_00a37f54 == 0,0);
    if ((*(byte *)(param_1 + 0x93184) & 1) != 0) {
      local_c = *(undefined4 *)(param_1 + 0x9361c);
      local_10 = *(int *)(param_1 + 0x935e4) / 2;
      local_8 = *(int *)(param_1 + 0x93620) + local_10;
      local_10 = *piVar1 + local_10;
      local_4 = *(undefined4 *)(param_1 + 0x93624);
      FUN_00523da0(param_1 + 0x931bc,0,&local_10,local_10,local_c,*(undefined4 *)(param_1 + 0x931b0)
                   ,DAT_00a37f54 == 0,0);
    }
  }
  return 0;
}

