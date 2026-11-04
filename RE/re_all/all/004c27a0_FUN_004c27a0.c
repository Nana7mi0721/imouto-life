
void __fastcall FUN_004c27a0(int param_1)

{
  short local_14;
  int local_8;
  
  if (-1 < *(short *)(param_1 + 0x902)) {
    for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
      *(short *)(param_1 + 0x8f0 + local_8 * 2) =
           *(short *)(param_1 + 0x8f6 + local_8 * 2) +
           (short)((((int)*(short *)(param_1 + 0x8fc + local_8 * 2) -
                    (int)*(short *)(param_1 + 0x8f6 + local_8 * 2)) *
                   (int)*(short *)(param_1 + 0x902)) / (int)*(short *)(param_1 + 0x904));
    }
    if (*(short *)(param_1 + 0x902) == 0) {
      *(undefined2 *)(param_1 + 0x902) = 0xffff;
    }
    else {
      if (*(short *)(param_1 + 0x902) - DAT_0084b244 < 1) {
        local_14 = 0;
      }
      else {
        local_14 = *(short *)(param_1 + 0x902) - (short)DAT_0084b244;
      }
      *(short *)(param_1 + 0x902) = local_14;
    }
  }
  if (0 < *(short *)(param_1 + 0x90c)) {
    *(short *)(param_1 + 0x90c) = *(short *)(param_1 + 0x90c) - (short)DAT_0084b244;
  }
  return;
}

