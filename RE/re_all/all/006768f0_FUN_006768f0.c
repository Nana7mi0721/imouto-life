
void FUN_006768f0(int param_1)

{
  *(undefined1 **)(param_1 + 0x2cc) = &LAB_00676940;
  *(undefined1 **)(param_1 + 0x2d0) = &LAB_00676980;
  *(undefined1 **)(param_1 + 0x2d4) = &LAB_006769b0;
  if ((*(byte *)(param_1 + 0x15a) + 7 & 0xfffffff8) == 8) {
    *(undefined1 **)(param_1 + 0x2d8) = &LAB_00676a20;
    return;
  }
  *(code **)(param_1 + 0x2d8) = FUN_00676ac0;
  return;
}

