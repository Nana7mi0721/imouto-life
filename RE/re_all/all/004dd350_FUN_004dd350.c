
void __fastcall FUN_004dd350(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_004dd320(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
    deallocate(*(undefined4 *)(param_1 + 4),
               (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) / 0x2740);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

