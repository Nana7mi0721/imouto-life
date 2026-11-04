
void FUN_006bdad0(undefined4 *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar3 = 0;
  puVar5 = param_1;
  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  if (0 < param_2) {
    iVar4 = 0x7f;
    do {
      cVar2 = (char)iVar3;
      if (-1 < iVar4 - param_2) {
        *(char *)((int)param_1 + (iVar4 - param_2)) = cVar2 - (char)param_2;
      }
      iVar1 = param_2 + 0x7f + iVar3;
      *(char *)(iVar4 + (int)param_1) = -cVar2;
      *(char *)((int)param_1 + iVar1 + (0x7f - (param_2 + 0x7f))) = cVar2;
      if (iVar1 < 0x100) {
        *(char *)((int)param_1 + param_2 + iVar3 + 0x7f) = -cVar2 + (char)param_2;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar3 < param_2);
  }
  return;
}

