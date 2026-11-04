
undefined1 __thiscall FUN_004789a0(int param_1,char param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  if (-1 < *(int *)(param_1 + 0x15c)) {
    if (param_2 == '\0') {
      FUN_004cf170(*(undefined4 *)(param_1 + 0x15c));
      iVar1 = FUN_004cd730();
      if (2 < iVar1) {
        uVar3 = 1;
        FUN_004cf170(*(undefined4 *)(param_1 + 0x15c));
        puVar2 = (undefined1 *)FUN_004cd7c0(uVar3);
        return *puVar2;
      }
    }
    else {
      FUN_004cf170(*(undefined4 *)(param_1 + 0x15c));
      iVar1 = FUN_004cd730();
      if (2 < iVar1) {
        uVar3 = 2;
        FUN_004cf170(*(undefined4 *)(param_1 + 0x15c));
        puVar2 = (undefined1 *)FUN_004cd7c0(uVar3);
        return *puVar2;
      }
    }
  }
  return 0;
}

