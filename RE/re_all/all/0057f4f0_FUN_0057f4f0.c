
undefined4 FUN_0057f4f0(int param_1)

{
  int iVar1;
  
  if (DAT_00a83c5c == 0) {
    FUN_0057f470();
    iVar1 = 5;
    do {
      FUN_005501a0();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  else if (DAT_00a83c5c - 1U < 2) {
    (**(code **)(*DAT_00aa4250 + 0xb8))(DAT_00aa4250,*(undefined4 *)(param_1 + 0x48),0,0,0);
  }
  if (DAT_00a834e0 == 1) {
    DeleteFileW(&DAT_00a828d8);
    DAT_00a834e0 = 0;
  }
  return 0;
}

