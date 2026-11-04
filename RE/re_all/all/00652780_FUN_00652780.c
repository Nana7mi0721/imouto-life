
void FUN_00652780(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 100);
  if (uVar1 == 0xffffffff) {
    uVar1 = 1;
  }
  else if (*(uint *)(param_1 + 0x3c) < -uVar1) {
    uVar1 = ((*(uint *)(param_1 + 0x3c) - 1) + uVar1) / uVar1;
  }
  else {
    uVar1 = 0;
  }
  if (*(short *)(param_1 + 0x7e) == 2) {
    FUN_00650ae0(param_1,uVar1,*(undefined2 *)(param_1 + 0x62),s_TIFFNumberOfStrips_00a06ff0);
  }
  return;
}

