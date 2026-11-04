
void FUN_0066c370(int *param_1,int param_2)

{
  byte bVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  bVar1 = *(byte *)(param_1 + 2);
  if ((bVar1 & 2) != 0) {
    iVar4 = *param_1;
    if (*(char *)((int)param_1 + 9) == '\b') {
      if (bVar1 == 2) {
        iVar7 = 3;
      }
      else {
        if (bVar1 != 6) {
          return;
        }
        iVar7 = 4;
      }
      if (iVar4 != 0) {
        pcVar2 = (char *)(param_2 + 2);
        do {
          pcVar2[-2] = pcVar2[-2] + pcVar2[-1];
          *pcVar2 = *pcVar2 + pcVar2[-1];
          pcVar2 = pcVar2 + iVar7;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        return;
      }
    }
    else if (*(char *)((int)param_1 + 9) == '\x10') {
      if (bVar1 == 2) {
        iVar7 = 6;
      }
      else {
        if (bVar1 != 6) {
          return;
        }
        iVar7 = 8;
      }
      if (iVar4 != 0) {
        puVar3 = (undefined1 *)(param_2 + 1);
        do {
          uVar6 = (uint)CONCAT11(puVar3[3],puVar3[4]) + (uint)CONCAT11(puVar3[1],puVar3[2]) & 0xffff
          ;
          uVar5 = (uint)CONCAT11(puVar3[-1],*puVar3) + (uint)CONCAT11(puVar3[1],puVar3[2]) & 0xffff;
          puVar3[4] = (char)uVar6;
          *puVar3 = (char)uVar5;
          puVar3[-1] = (char)(uVar5 >> 8);
          puVar3[3] = (char)(uVar6 >> 8);
          puVar3 = puVar3 + iVar7;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
  }
  return;
}

