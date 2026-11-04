
void FUN_00688060(int param_1)

{
  int iVar1;
  char cVar2;
  
  iVar1 = *(int *)(param_1 + 0x1a0);
  if (*(int *)(iVar1 + 0x10) != 0) {
    if (*(char *)(param_1 + 0x49) != '\0') {
      cVar2 = FUN_006886e0(param_1);
      if (cVar2 != '\0') {
        *(undefined1 **)(iVar1 + 0xc) = &LAB_00688800;
        *(undefined4 *)(param_1 + 0x88) = 0;
        return;
      }
    }
    *(undefined1 **)(iVar1 + 0xc) = &LAB_00688530;
  }
  *(undefined4 *)(param_1 + 0x88) = 0;
  return;
}

