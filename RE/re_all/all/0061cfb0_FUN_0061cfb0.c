
void __thiscall FUN_0061cfb0(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int local_c;
  
  iVar8 = param_3;
  if (*(char *)(param_1 + 0x1c) == '\0') {
    iVar8 = param_2;
  }
  local_c = param_2;
  if (*(char *)(param_1 + 0x1c) == '\0') {
    local_c = param_3;
  }
  iVar2 = *(int *)(iVar8 + 0xc0);
  iVar3 = *(int *)(iVar2 + 0x10);
  iVar7 = *(int *)(param_1 + 0xc);
  if (iVar7 <= iVar3) {
    if (iVar7 < iVar3) {
      FUN_0078e010(iVar3);
    }
    for (; iVar7 < iVar3; iVar7 = iVar7 + 1) {
      puVar1 = (undefined4 *)(*(int *)(param_1 + 0x14) + iVar7 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = 0;
      }
    }
  }
  *(int *)(param_1 + 0xc) = iVar3;
  iVar7 = 0;
  if (0 < iVar3) {
    param_2 = 0;
    do {
      if (*(int *)(iVar2 + 0x40) == 0) {
        uVar4 = *(undefined4 *)(iVar8 + 0xc0);
        *(undefined4 *)(iVar8 + 0xc0) = *(undefined4 *)(*(int *)(iVar2 + 0x18) + 0x40 + param_2);
        iVar5 = *(int *)(param_1 + 0x14);
        uVar6 = (**(code **)(**(int **)(param_1 + 4) + 4))
                          (iVar8,local_c,*(undefined4 *)(param_1 + 0x20));
        *(undefined4 *)(iVar5 + iVar7 * 4) = uVar6;
        *(undefined4 *)(iVar8 + 0xc0) = uVar4;
      }
      else {
        *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar7 * 4) = 0;
      }
      iVar7 = iVar7 + 1;
      param_2 = param_2 + 0x50;
    } while (iVar7 < iVar3);
  }
  return;
}

