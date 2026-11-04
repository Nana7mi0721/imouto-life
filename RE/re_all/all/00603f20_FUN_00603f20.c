
void __fastcall FUN_00603f20(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x160) != 0) {
    if ((*(int *)(param_1 + 0x170) == 1) && (*(int *)(param_1 + 0x174) == 0)) {
      pvVar1 = operator_new(0x440);
      *(void **)(param_1 + 0x174) = pvVar1;
      FUN_00546d10(*(undefined4 *)(param_1 + 400),*(undefined4 *)(param_1 + 0x194),pvVar1);
    }
    if (*(int *)(param_1 + 0x17c) == 0) {
      uVar2 = FUN_0056e030(*(int *)(param_1 + 0x198) * *(int *)(param_1 + 0x194),
                           s_D__DxLib_Develop_Source_Library__00a06048,0x2185);
      *(undefined4 *)(param_1 + 0x17c) = uVar2;
    }
    if ((((*(int *)(param_1 + 0x180) == 0) && (*(int *)(param_1 + 0x164) == 0)) &&
        (*(int *)(param_1 + 0x178) != 0)) && (*(int *)(param_1 + 0x178) != 1)) {
      iVar3 = FUN_0056e030(*(int *)(param_1 + 0x1b0) * *(int *)(param_1 + 0x1ac) +
                           *(int *)(param_1 + 0x1a0) * *(int *)(param_1 + 0x1a4),
                           s_D__DxLib_Develop_Source_Library__00a06048,0x218a);
      *(int *)(param_1 + 0x180) = iVar3;
      *(int *)(param_1 + 0x184) = *(int *)(param_1 + 0x1a0) * *(int *)(param_1 + 0x1a4) + iVar3;
    }
  }
  return;
}

