
void FUN_006c26a0(int param_1)

{
  *(undefined4 *)(param_1 + 0x68) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x74) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x21d4) = 0;
  *(undefined4 *)(param_1 + 0x2200) = 0;
  if (*(int *)(param_1 + 0x14) == 0) {
    FUN_006c4970(*(int *)(param_1 + 0x1c) + 0x14c);
  }
  *(undefined4 *)(param_1 + 0x5c) = 2;
  return;
}

