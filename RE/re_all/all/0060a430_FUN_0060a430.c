
/* WARNING: Removing unreachable block (ram,0x0060a44e) */

undefined8 __thiscall FUN_0060a430(int param_1,longlong *param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  int iVar3;
  
  iVar3 = (*DAT_00aba168)();
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  lVar2 = (longlong)(iVar3 - *(int *)(param_1 + 0x34)) * (longlong)*(int *)(param_1 + 0x30);
  if (lVar2 < *(longlong *)(param_1 + 0x20)) {
    *param_2 = lVar2;
    return *(undefined8 *)(param_1 + 0x20);
  }
  *(undefined4 *)param_2 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)((int)param_2 + 4) = uVar1;
  return *(undefined8 *)(param_1 + 0x20);
}

