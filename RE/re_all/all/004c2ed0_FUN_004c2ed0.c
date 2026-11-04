
void __fastcall FUN_004c2ed0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_00a18a4c;
  if (DAT_00a18a48 == -1) {
    *(float *)(param_1 + 0x54) = (float)(DAT_0084b230 / 0x28);
  }
  else {
    *(float *)(param_1 + 0x54) = (float)(DAT_00a18a48 * DAT_0084b248);
  }
  if (iVar1 == -1) {
    uVar2 = FUN_004fe844();
    *(undefined4 *)(param_1 + 0x264) = uVar2;
  }
  else {
    *(int *)(param_1 + 0x264) = iVar1 * DAT_0084b248;
  }
  *(float *)(param_1 + 0x58) = (float)*(int *)(param_1 + 0x264);
  *(undefined4 *)(param_1 + 0x25c) = 1;
  return;
}

