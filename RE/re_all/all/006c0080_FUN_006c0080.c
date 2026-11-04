
void FUN_006c0080(int param_1)

{
  void *_Memory;
  int iVar1;
  int iVar2;
  
  _free(*(void **)(param_1 + 0x21f8));
  if (*(int *)(param_1 + 0x21d8) != 0) {
    FUN_006507e0(*(int *)(param_1 + 0x21d8));
  }
  _Memory = *(void **)(param_1 + 0x1c);
  if (*(int *)(param_1 + 0x14) == 0) {
    if ((2 < *(int *)(param_1 + 0x5c)) || (*(int *)(param_1 + 0x5c) == 1)) {
      FUN_006c4970((int)_Memory + 0x14c);
    }
  }
  else if ((_Memory != (void *)0x0) && (iVar1 = *(int *)(param_1 + 0x18), 0 < iVar1)) {
    iVar2 = (int)_Memory + 0x14c;
    do {
      FUN_006c4970(iVar2);
      iVar2 = iVar2 + 0x160;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  _free(_Memory);
  _free(*(void **)(param_1 + 0x28));
  FUN_006a8490(param_1 + 0x88);
  FUN_006a86c0(param_1 + 0x40);
  if (*(code **)(param_1 + 0xc) != (code *)0x0) {
    (**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 0x10));
  }
  return;
}

