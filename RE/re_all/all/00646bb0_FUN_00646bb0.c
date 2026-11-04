
void FUN_00646bb0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00650930(param_1);
  }
  (**(code **)(param_1 + 0x234))(param_1);
  FUN_0064e340(param_1);
  if (*(int *)(param_1 + 0x20) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0x20));
  }
  puVar1 = *(undefined4 **)(param_1 + 0x2a8);
  while (puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x2a8) = *puVar1;
    FUN_006507e0(puVar1[2]);
    FUN_006507e0(puVar1);
    puVar1 = *(undefined4 **)(param_1 + 0x2a8);
  }
  if ((*(int *)(param_1 + 0x24c) != 0) && ((*(uint *)(param_1 + 0xc) & 0x200) != 0)) {
    FUN_006507e0(*(int *)(param_1 + 0x24c));
  }
  if ((*(uint *)(param_1 + 0xc) & 0x800) != 0) {
    (**(code **)(param_1 + 0x270))
              (*(undefined4 *)(param_1 + 0x274),*(undefined4 *)(param_1 + 0x264),
               *(int *)(param_1 + 0x268),*(int *)(param_1 + 0x268) >> 0x1f);
  }
  if ((*(int *)(param_1 + 0x290) != 0) && (*(int *)(param_1 + 0x294) != 0)) {
    uVar3 = 0;
    if (*(int *)(param_1 + 0x294) != 0) {
      do {
        iVar4 = *(int *)(*(int *)(param_1 + 0x290) + uVar3 * 4);
        if ((*(short *)(iVar4 + 0x18) == 0x41) &&
           (iVar2 = _strncmp(&DAT_00a06274,*(char **)(iVar4 + 0x1c),4), iVar2 == 0)) {
          FUN_006507e0(*(undefined4 *)(iVar4 + 0x1c));
          FUN_006507e0(iVar4);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(param_1 + 0x294));
    }
    FUN_006507e0(*(undefined4 *)(param_1 + 0x290));
  }
  if (*(int *)(param_1 + 0x2b0) != 0) {
    uVar3 = 0;
    if (*(int *)(param_1 + 0x2b0) != 0) {
      iVar4 = 0;
      do {
        if (*(int *)(iVar4 + 4 + *(int *)(param_1 + 0x2ac)) != 0) {
          FUN_006507e0(*(undefined4 *)(iVar4 + *(int *)(param_1 + 0x2ac) + 0xc));
        }
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 0x10;
      } while (uVar3 < *(uint *)(param_1 + 0x2b0));
    }
    FUN_006507e0(*(undefined4 *)(param_1 + 0x2ac));
  }
  FUN_006507e0(param_1);
  return;
}

