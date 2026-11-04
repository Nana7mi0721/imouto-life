
void __fastcall FUN_004d8af0(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_004d8ac0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
    deallocate(*(undefined4 *)(param_1 + 4),(*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) / 0x54
              );
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

