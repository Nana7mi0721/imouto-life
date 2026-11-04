
void FUN_0066b390(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 400));
  *(undefined4 *)(param_1 + 400) = 0;
  if (*(int *)(param_1 + 0x194) != 0) {
    iVar2 = 1 << (8U - (char)*(undefined4 *)(param_1 + 0x188) & 0x1f);
    iVar1 = 0;
    if (0 < iVar2) {
      do {
        FUN_0066cb60(param_1,*(undefined4 *)(*(int *)(param_1 + 0x194) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < iVar2);
    }
    FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x194));
    *(undefined4 *)(param_1 + 0x194) = 0;
  }
  FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x198));
  *(undefined4 *)(param_1 + 0x198) = 0;
  FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x19c));
  *(undefined4 *)(param_1 + 0x19c) = 0;
  if (*(int *)(param_1 + 0x1a0) != 0) {
    iVar2 = 1 << (8U - (char)*(undefined4 *)(param_1 + 0x188) & 0x1f);
    iVar1 = 0;
    if (0 < iVar2) {
      do {
        FUN_0066cb60(param_1,*(undefined4 *)(*(int *)(param_1 + 0x1a0) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < iVar2);
    }
    FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x1a0));
    *(undefined4 *)(param_1 + 0x1a0) = 0;
  }
  if (*(int *)(param_1 + 0x1a4) != 0) {
    iVar2 = 1 << (8U - (char)*(undefined4 *)(param_1 + 0x188) & 0x1f);
    iVar1 = 0;
    if (0 < iVar2) {
      do {
        FUN_0066cb60(param_1,*(undefined4 *)(*(int *)(param_1 + 0x1a4) + iVar1 * 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < iVar2);
    }
    FUN_0066cb60(param_1,*(undefined4 *)(param_1 + 0x1a4));
    *(undefined4 *)(param_1 + 0x1a4) = 0;
  }
  return;
}

