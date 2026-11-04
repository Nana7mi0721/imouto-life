
undefined4 FUN_00652360(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0xc) = uVar1 & 0xff7fffff;
  if (*(int *)(param_1 + 0x24c) != 0) {
    if ((uVar1 & 0x200) != 0) {
      FUN_006507e0(*(int *)(param_1 + 0x24c));
    }
    *(undefined4 *)(param_1 + 0x24c) = 0;
    *(undefined4 *)(param_1 + 0x250) = 0;
  }
  if (param_2 == 0) {
    iVar2 = __aullshr();
    *(int *)(param_1 + 0x250) = iVar2 << 10;
    if (iVar2 << 10 == 0) {
      *(undefined4 *)(param_1 + 0x250) = 0xffffffff;
    }
    uVar3 = FUN_006507d0(*(undefined4 *)(param_1 + 0x250));
    *(undefined4 *)(param_1 + 0x24c) = uVar3;
    uVar1 = *(uint *)(param_1 + 0xc) | 0x200;
  }
  else {
    *(int *)(param_1 + 0x24c) = param_2;
    *(undefined4 *)(param_1 + 0x250) = param_3;
    uVar1 = *(uint *)(param_1 + 0xc) & 0xfffffdff;
  }
  *(uint *)(param_1 + 0xc) = uVar1;
  if (*(int *)(param_1 + 0x24c) == 0) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFReadBufferSetup",
                 s_No_space_for_data_buffer_at_scan_00a06f50,*(undefined4 *)(param_1 + 0x1bc));
    *(undefined4 *)(param_1 + 0x250) = 0;
    return 0;
  }
  return 1;
}

