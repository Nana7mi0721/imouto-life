
void FUN_006abab0(undefined4 *param_1)

{
  void *_Memory;
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = (void *)param_1[7];
  if (_Memory != (void *)0x0) {
    iVar1 = 0;
    if (0 < *(int *)((int)_Memory + 8)) {
      puVar3 = (undefined4 *)((int)_Memory + 0x20);
      do {
        if ((void *)*puVar3 != (void *)0x0) {
          _free((void *)*puVar3);
        }
        iVar1 = iVar1 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar1 < *(int *)((int)_Memory + 8));
    }
    iVar1 = 0;
    if (0 < *(int *)((int)_Memory + 0xc)) {
      piVar2 = (int *)((int)_Memory + 0x220);
      do {
        if (*piVar2 != 0) {
          (**(code **)((&PTR_PTR_008298d8)[piVar2[-0x40]] + 8))(*piVar2);
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar1 < *(int *)((int)_Memory + 0xc));
    }
    iVar1 = 0;
    if (0 < *(int *)((int)_Memory + 0x10)) {
      piVar2 = (int *)((int)_Memory + 0x420);
      do {
        if (*piVar2 != 0) {
          (**(code **)((&PTR_DAT_008298c4)[piVar2[-0x40]] + 0xc))(*piVar2);
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar1 < *(int *)((int)_Memory + 0x10));
    }
    iVar1 = 0;
    if (0 < *(int *)((int)_Memory + 0x14)) {
      piVar2 = (int *)((int)_Memory + 0x620);
      do {
        if (*piVar2 != 0) {
          (**(code **)((&PTR_DAT_008298cc)[piVar2[-0x40]] + 0xc))(*piVar2);
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar1 < *(int *)((int)_Memory + 0x14));
    }
    iVar1 = 0;
    if (0 < *(int *)((int)_Memory + 0x18)) {
      iVar4 = 0;
      piVar2 = (int *)((int)_Memory + 0x720);
      do {
        if (*piVar2 != 0) {
          FUN_006b00c0(*piVar2);
        }
        if (*(int *)((int)_Memory + 0xb20) != 0) {
          FUN_006b0110(*(int *)((int)_Memory + 0xb20) + iVar4);
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 1;
        iVar4 = iVar4 + 0x38;
      } while (iVar1 < *(int *)((int)_Memory + 0x18));
    }
    if (*(void **)((int)_Memory + 0xb20) != (void *)0x0) {
      _free(*(void **)((int)_Memory + 0xb20));
    }
    iVar1 = 0;
    if (0 < *(int *)((int)_Memory + 0x1c)) {
      puVar3 = (undefined4 *)((int)_Memory + 0xb24);
      do {
        FUN_006ad590(*puVar3);
        iVar1 = iVar1 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar1 < *(int *)((int)_Memory + 0x1c));
    }
    _free(_Memory);
  }
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return;
}

