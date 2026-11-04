
void __thiscall FUN_0078e3f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar5 = 0;
  if (0 < *(int *)(param_2 + 8)) {
    do {
      iVar1 = *(int *)(*(int *)(param_2 + 0x10) + iVar5 * 4);
      if ((*(byte *)(iVar1 + 200) & 3) == 0) {
        iVar2 = *(int *)(param_1 + 0x10);
        iVar6 = iVar5 * 8;
        iVar4 = *(int *)(iVar6 + iVar2);
        puVar7 = (undefined4 *)(iVar6 + iVar2);
        iVar3 = iVar5;
        if (iVar5 != iVar4) {
          do {
            *puVar7 = *(undefined4 *)(iVar2 + iVar4 * 8);
            iVar2 = *(int *)(param_1 + 0x10);
            iVar3 = *(int *)(iVar2 + iVar6);
            iVar6 = iVar3 * 8;
            iVar4 = *(int *)(iVar2 + iVar6);
            puVar7 = (undefined4 *)(iVar2 + iVar6);
          } while (iVar3 != iVar4);
        }
        *(int *)(iVar1 + 0xcc) = iVar3;
        *(undefined4 *)(iVar1 + 0xd0) = 0xffffffff;
      }
      else {
        *(undefined4 *)(iVar1 + 0xcc) = 0xffffffff;
        *(undefined4 *)(iVar1 + 0xd0) = 0xfffffffe;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_2 + 8));
  }
  return;
}

