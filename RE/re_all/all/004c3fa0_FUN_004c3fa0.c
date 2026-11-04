
void __fastcall FUN_004c3fa0(int param_1)

{
  if (DAT_00a18ae4 == '\0') {
    *(undefined4 *)(param_1 + 0x128) = 0;
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  if (DAT_00a18ae4 == '\x01') {
    *(undefined4 *)(param_1 + 0x128) = 1;
  }
  if (DAT_00a18a50 == -1) {
    *(int *)(param_1 + 0x180) = DAT_0084b264 * 10 - *(int *)(param_1 + 0x188) / 2;
  }
  else {
    *(int *)(param_1 + 0x180) = DAT_00a18a50 - *(int *)(param_1 + 0x188) / 2;
  }
  if (DAT_00a18a54 == -1) {
    *(int *)(param_1 + 0x184) = (int)(0xaa / (longlong)DAT_0084b248) - *(int *)(param_1 + 0x18c) / 2
    ;
  }
  else {
    *(int *)(param_1 + 0x184) = DAT_00a18a54;
  }
  *(float *)(param_1 + 0x54) =
       (float)((*(int *)(param_1 + 0x180) + 2 + (DAT_0084b264 << 2) / 10) * DAT_0084b248);
  *(float *)(param_1 + 0x58) =
       (float)((*(int *)(param_1 + 0x184) + 2 + (DAT_0084b264 << 2) / 10) * DAT_0084b248);
  *(undefined4 *)(param_1 + 0x17c) = 1;
  return;
}

