
void FUN_0066e540(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  bVar1 = *(byte *)((int)param_1 + 9);
  if (bVar1 < 8) {
    iVar2 = *param_1;
    if (bVar1 == 1) {
      pbVar6 = (byte *)((iVar2 - 1U >> 3) + param_2);
      pbVar5 = (byte *)(iVar2 + -1 + param_2);
      iVar3 = 7 - (iVar2 - 1U & 7);
      if (iVar2 != 0) {
        iVar4 = iVar2;
        do {
          *pbVar5 = *pbVar6 >> ((byte)iVar3 & 0x1f) & 1;
          if (iVar3 == 7) {
            iVar3 = 0;
            pbVar6 = pbVar6 + -1;
          }
          else {
            iVar3 = iVar3 + 1;
          }
          pbVar5 = pbVar5 + -1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
    else if (bVar1 == 2) {
      pbVar6 = (byte *)((iVar2 - 1U >> 2) + param_2);
      pbVar5 = (byte *)(iVar2 + -1 + param_2);
      iVar3 = (iVar2 - 1U & 3) * -2 + 6;
      if (iVar2 != 0) {
        iVar4 = iVar2;
        do {
          *pbVar5 = *pbVar6 >> ((byte)iVar3 & 0x1f) & 3;
          if (iVar3 == 6) {
            iVar3 = 0;
            pbVar6 = pbVar6 + -1;
          }
          else {
            iVar3 = iVar3 + 2;
          }
          pbVar5 = pbVar5 + -1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
    else if (bVar1 == 4) {
      pbVar6 = (byte *)((iVar2 - 1U >> 1) + param_2);
      pbVar5 = (byte *)(iVar2 + -1 + param_2);
      iVar3 = (iVar2 - 1U & 1) * -4 + 4;
      if (iVar2 != 0) {
        param_2 = iVar2;
        do {
          *pbVar5 = *pbVar6 >> ((byte)iVar3 & 0x1f) & 0xf;
          if (iVar3 == 4) {
            iVar3 = 0;
            pbVar6 = pbVar6 + -1;
          }
          else {
            iVar3 = 4;
          }
          pbVar5 = pbVar5 + -1;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
    }
    *(undefined1 *)((int)param_1 + 9) = 8;
    *(byte *)((int)param_1 + 0xb) = *(byte *)((int)param_1 + 10) << 3;
    param_1[1] = (uint)*(byte *)((int)param_1 + 10) * iVar2;
  }
  return;
}

