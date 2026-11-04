
void __fastcall FUN_0063bf20(int param_1)

{
  if ((*(byte *)(param_1 + 200) & 3) == 0) {
    *(float *)(param_1 + 0x1a4) =
         *(float *)(param_1 + 0x164) * *(float *)(param_1 + 0x174) + *(float *)(param_1 + 0x1a4);
    *(float *)(param_1 + 0x1a8) =
         *(float *)(param_1 + 0x168) * *(float *)(param_1 + 0x178) + *(float *)(param_1 + 0x1a8);
    *(float *)(param_1 + 0x1ac) =
         *(float *)(param_1 + 0x16c) * *(float *)(param_1 + 0x17c) + *(float *)(param_1 + 0x1ac);
  }
  return;
}

