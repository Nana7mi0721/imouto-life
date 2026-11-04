
undefined4 FUN_00668c20(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x44) == 0) {
    *(undefined4 *)(param_1 + 0x48) = 0;
    if (0x40 < param_3) {
      iVar1 = FUN_0066cb30(param_1,param_3);
      *(int *)(param_1 + 0x44) = iVar1;
      if (iVar1 == 0) {
        return 0;
      }
      *(uint *)(param_1 + 0x48) = param_3;
      *(undefined4 *)(param_1 + 0x40) = param_2;
      return *(undefined4 *)(param_1 + 0x44);
    }
    *(int *)(param_1 + 0x44) = param_1;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x48);
    if ((uVar2 == 0) && (uVar2 = 0x40, *(int *)(param_1 + 0x44) != param_1)) {
      FUN_00668620(param_1,s_Libpng_jmp_buf_still_allocated_00a0bc08);
    }
    if (uVar2 != param_3) {
      FUN_006687b0(param_1,s_Application_jmp_buf_size_changed_00a0bbe4);
      return 0;
    }
  }
  *(undefined4 *)(param_1 + 0x40) = param_2;
  return *(undefined4 *)(param_1 + 0x44);
}

