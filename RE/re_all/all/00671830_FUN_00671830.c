
void FUN_00671830(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  iVar1 = param_1;
  if ((param_1 != 0) && (param_1 = FUN_0066cc40(param_1), 0 < param_1)) {
    do {
      uVar3 = 0;
      puVar2 = param_2;
      if (*(int *)(iVar1 + 0x104) != 0) {
        do {
          FUN_00671890(iVar1,*puVar2);
          uVar3 = uVar3 + 1;
          puVar2 = puVar2 + 1;
        } while (uVar3 < *(uint *)(iVar1 + 0x104));
      }
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}

