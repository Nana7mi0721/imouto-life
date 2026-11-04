
void FUN_0064e340(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_00650810(param_1 + 0x28,0,4);
  if (*(int *)(param_1 + 0x6c) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0x6c));
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  if (*(int *)(param_1 + 0x70) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0x70));
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  if (*(int *)(param_1 + 0x8c) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0x8c));
    *(undefined4 *)(param_1 + 0x8c) = 0;
  }
  if (*(int *)(param_1 + 0x90) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0x90));
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  if (*(int *)(param_1 + 0x94) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0x94));
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  if (*(int *)(param_1 + 0xa0) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0xa0));
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  if (*(int *)(param_1 + 0xbc) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0xbc));
    *(undefined4 *)(param_1 + 0xbc) = 0;
  }
  if (*(int *)(param_1 + 0xdc) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0xdc));
    *(undefined4 *)(param_1 + 0xdc) = 0;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0xd4));
    *(undefined4 *)(param_1 + 0xd4) = 0;
  }
  if (*(int *)(param_1 + 200) != 0) {
    FUN_006507e0(*(int *)(param_1 + 200));
    *(undefined4 *)(param_1 + 200) = 0;
  }
  if (*(int *)(param_1 + 0xcc) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0xcc));
    *(undefined4 *)(param_1 + 0xcc) = 0;
  }
  if (*(int *)(param_1 + 0xd0) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0xd0));
    *(undefined4 *)(param_1 + 0xd0) = 0;
  }
  if (*(int *)(param_1 + 0xac) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0xac));
    *(undefined4 *)(param_1 + 0xac) = 0;
  }
  if (*(int *)(param_1 + 0xb0) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0xb0));
    *(undefined4 *)(param_1 + 0xb0) = 0;
  }
  iVar3 = 0;
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xfffffe7f;
  if (0 < *(int *)(param_1 + 0xe0)) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0xe4) + 8 + iVar2);
      if (iVar1 != 0) {
        FUN_006507e0(iVar1);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xc;
    } while (iVar3 < *(int *)(param_1 + 0xe0));
  }
  *(undefined4 *)(param_1 + 0xe0) = 0;
  if (*(int *)(param_1 + 0xe4) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0xe4));
    *(undefined4 *)(param_1 + 0xe4) = 0;
  }
  return;
}

