
void FUN_006acb60(undefined4 *param_1)

{
  int *_Memory;
  void *_Memory_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1 != (undefined4 *)0x0) {
    iVar1 = param_1[1];
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x1c);
    }
    _Memory = (int *)param_1[0x1a];
    if (_Memory != (int *)0x0) {
      if (*_Memory != 0) {
        FUN_006b1420(*_Memory);
        _free((void *)*_Memory);
      }
      if ((undefined4 *)_Memory[3] != (undefined4 *)0x0) {
        FUN_006b2c50(*(undefined4 *)_Memory[3]);
        _free(*(void **)_Memory[3]);
        _free((void *)_Memory[3]);
      }
      if ((undefined4 *)_Memory[4] != (undefined4 *)0x0) {
        FUN_006b2c50(*(undefined4 *)_Memory[4]);
        _free(*(void **)_Memory[4]);
        _free((void *)_Memory[4]);
      }
      if (_Memory[0xc] != 0) {
        if ((iVar2 != 0) && (iVar3 = 0, 0 < *(int *)(iVar2 + 0x10))) {
          piVar4 = (int *)(iVar2 + 800);
          do {
            (**(code **)((&PTR_DAT_008298c4)[*piVar4] + 0x10))
                      (*(undefined4 *)(_Memory[0xc] + iVar3 * 4));
            iVar3 = iVar3 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar3 < *(int *)(iVar2 + 0x10));
        }
        _free((void *)_Memory[0xc]);
      }
      if (_Memory[0xd] != 0) {
        if ((iVar2 != 0) && (iVar3 = 0, 0 < *(int *)(iVar2 + 0x14))) {
          piVar4 = (int *)(iVar2 + 0x520);
          do {
            (**(code **)((&PTR_DAT_008298cc)[*piVar4] + 0x10))
                      (*(undefined4 *)(_Memory[0xd] + iVar3 * 4));
            iVar3 = iVar3 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar3 < *(int *)(iVar2 + 0x14));
        }
        _free((void *)_Memory[0xd]);
      }
      if (_Memory[0xe] != 0) {
        if ((iVar2 != 0) && (iVar3 = 0, 0 < *(int *)(iVar2 + 0x1c))) {
          iVar5 = 0;
          do {
            FUN_006ae360(iVar5 + _Memory[0xe]);
            iVar3 = iVar3 + 1;
            iVar5 = iVar5 + 0x34;
          } while (iVar3 < *(int *)(iVar2 + 0x1c));
        }
        _free((void *)_Memory[0xe]);
      }
      if (_Memory[0xf] != 0) {
        FUN_006ad570(_Memory[0xf]);
      }
      FUN_006b13f0(_Memory + 0x14);
      FUN_006b2a30(_Memory + 5);
      FUN_006b2a30(_Memory + 8);
    }
    if (param_1[2] != 0) {
      if ((iVar1 != 0) && (iVar2 = 0, 0 < *(int *)(iVar1 + 4))) {
        do {
          _Memory_00 = *(void **)(param_1[2] + iVar2 * 4);
          if (_Memory_00 != (void *)0x0) {
            _free(_Memory_00);
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(iVar1 + 4));
      }
      _free((void *)param_1[2]);
      if ((void *)param_1[3] != (void *)0x0) {
        _free((void *)param_1[3]);
      }
    }
    if (_Memory != (int *)0x0) {
      if ((void *)_Memory[0x10] != (void *)0x0) {
        _free((void *)_Memory[0x10]);
      }
      if ((void *)_Memory[0x11] != (void *)0x0) {
        _free((void *)_Memory[0x11]);
      }
      if ((void *)_Memory[0x12] != (void *)0x0) {
        _free((void *)_Memory[0x12]);
      }
      _free(_Memory);
    }
    for (iVar1 = 0x1c; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = 0;
      param_1 = param_1 + 1;
    }
  }
  return;
}

