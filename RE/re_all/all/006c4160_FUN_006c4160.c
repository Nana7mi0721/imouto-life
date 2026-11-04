
int FUN_006c4160(int param_1)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar1 = 8;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x18);
    iVar1 = 1;
    if (0 < iVar4) {
      piVar3 = (int *)(*(int *)(param_1 + 0x1c) + 0x30);
      do {
        if (iVar1 <= *piVar3) {
          iVar1 = *piVar3;
        }
        piVar3 = piVar3 + 0x58;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  pvVar2 = _malloc(iVar1 * 0x5a00);
  *(void **)(param_1 + 0x21f8) = pvVar2;
  return (-(uint)(pvVar2 != (void *)0x0) & 0x81) - 0x81;
}

