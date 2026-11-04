
void FUN_0079fcd0(int param_1,char *param_2,char *param_3,int param_4,int param_5)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = 0;
  if (0 < param_5) {
    do {
      if ((iVar5 == 0) && (param_4 == 0)) {
        iVar3 = *param_3 + -0x10;
        if (*param_3 + -0x10 < (int)*param_2) {
          iVar3 = (int)*param_2;
        }
        *param_3 = (char)iVar3;
      }
      else {
        cVar2 = *param_3;
        cVar1 = (char)(param_2[iVar5] + -4);
        if (cVar2 + 8 < param_2[iVar5] + -4) {
          *param_3 = (cVar1 * '\x02' - (char)(cVar2 + 8)) + cVar2;
        }
        else {
          *param_3 = cVar2 + cVar1;
        }
      }
      cVar2 = *param_3;
      if (cVar2 < '@') {
        if (cVar2 < '\0') {
          cVar2 = '\0';
        }
      }
      else {
        cVar2 = '?';
      }
      *param_3 = cVar2;
      iVar3 = (cVar2 * 0x1c71 >> 0x10) + 0x82a + cVar2 * 0x1d;
      if (0xf7e < iVar3) {
        iVar3 = 0xf7f;
      }
      uVar4 = FUN_007a01c0(iVar3);
      *(undefined4 *)(param_1 + iVar5 * 4) = uVar4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_5);
  }
  return;
}

