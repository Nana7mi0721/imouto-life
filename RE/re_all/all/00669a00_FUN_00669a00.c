
undefined4 FUN_00669a00(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_24 [36];
  
  iVar1 = FUN_00669a80(local_24,param_3);
  if (iVar1 == 0) {
    uVar2 = FUN_0066a110(param_1,param_2,param_3,local_24,param_4);
    return uVar2;
  }
  if (iVar1 == 1) {
    *(byte *)(param_2 + 0x4b) = *(byte *)(param_2 + 0x4b) | 0x80;
    FUN_00668960(param_1,s_invalid_chromaticities_00a0be4c);
    return 0;
  }
  *(byte *)(param_2 + 0x4b) = *(byte *)(param_2 + 0x4b) | 0x80;
  FUN_00668620(param_1,s_internal_error_checking_chromati_00a0be64);
  return 0;
}

