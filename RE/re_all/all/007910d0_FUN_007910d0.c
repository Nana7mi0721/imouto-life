
void __thiscall FUN_007910d0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 <= param_2) {
    if ((iVar3 < param_2) && (*(int *)(param_1 + 8) < param_2)) {
      uVar2 = FUN_00791290(param_2);
      FUN_00621e00(0,*(undefined4 *)(param_1 + 4),uVar2);
      FUN_0060b970(0,*(undefined4 *)(param_1 + 4));
      FUN_007932e0();
      *(undefined4 *)(param_1 + 0xc) = uVar2;
      *(undefined1 *)(param_1 + 0x10) = 1;
      *(int *)(param_1 + 8) = param_2;
    }
    for (; iVar3 < param_2; iVar3 = iVar3 + 1) {
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0xc) + iVar3 * 8);
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = local_8;
        puVar1[1] = local_4;
      }
    }
  }
  iVar3 = 0;
  *(int *)(param_1 + 4) = param_2;
  if (0 < param_2) {
    do {
      *(int *)(*(int *)(param_1 + 0xc) + iVar3 * 8) = iVar3;
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 4 + iVar3 * 8) = 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2);
  }
  return;
}

