
char FUN_0067e680(int *param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  char *pcVar6;
  char *pcVar5;
  int iVar7;
  char *pcVar8;
  bool bVar9;
  
  do {
    pcVar8 = (char *)param_1[0x1d];
    if (pcVar8 < (char *)0x103) {
      FUN_0067d900(param_1);
      pcVar8 = (char *)param_1[0x1d];
      if ((pcVar8 < (char *)0x103) && (param_2 == 0)) {
        return '\0';
      }
      if (pcVar8 == (char *)0x0) {
        param_1[0x5ad] = 0;
        if (param_2 == 4) {
          iVar3 = param_1[0x17];
          if (iVar3 < 0) {
            iVar7 = 0;
          }
          else {
            iVar7 = param_1[0xe] + iVar3;
          }
          FUN_0067f720(param_1,iVar7,param_1[0x1b] - iVar3,1);
          param_1[0x17] = param_1[0x1b];
          FUN_0067d730(*param_1);
          return (*(int *)(*param_1 + 0x10) != 0) + '\x02';
        }
        if (param_1[0x5a8] != 0) {
          iVar3 = param_1[0x17];
          if (iVar3 < 0) {
            iVar7 = 0;
          }
          else {
            iVar7 = param_1[0xe] + iVar3;
          }
          FUN_0067f720(param_1,iVar7,param_1[0x1b] - iVar3,0);
          param_1[0x17] = param_1[0x1b];
          FUN_0067d730(*param_1);
          if (*(int *)(*param_1 + 0x10) == 0) {
            return '\0';
          }
        }
        return '\x01';
      }
    }
    param_1[0x18] = 0;
    if (((char *)0x2 < pcVar8) && (param_1[0x1b] != 0)) {
      pcVar1 = (char *)(param_1[0xe] + param_1[0x1b]);
      cVar2 = pcVar1[-1];
      if ((cVar2 == *pcVar1) && ((cVar2 == pcVar1[1] && (cVar2 == pcVar1[2])))) {
        pcVar6 = pcVar1 + 2;
        do {
          pcVar5 = pcVar6 + 1;
          if (((((cVar2 != *pcVar5) || (pcVar5 = pcVar6 + 2, cVar2 != *pcVar5)) ||
               (pcVar5 = pcVar6 + 3, cVar2 != *pcVar5)) ||
              ((pcVar5 = pcVar6 + 4, cVar2 != *pcVar5 || (pcVar5 = pcVar6 + 5, cVar2 != *pcVar5))))
             || ((pcVar5 = pcVar6 + 6, cVar2 != *pcVar5 ||
                 ((pcVar5 = pcVar6 + 7, cVar2 != *pcVar5 || (pcVar5 = pcVar6 + 8, cVar2 != *pcVar5))
                 )))) break;
          pcVar6 = pcVar5;
        } while (pcVar5 < pcVar1 + 0x102);
        param_1[0x18] = (int)(pcVar5 + (0x102 - (int)(pcVar1 + 0x102)));
        if (pcVar8 < pcVar5 + (0x102 - (int)(pcVar1 + 0x102))) {
          param_1[0x18] = (int)pcVar8;
        }
      }
    }
    if ((uint)param_1[0x18] < 3) {
      bVar4 = *(byte *)(param_1[0xe] + param_1[0x1b]);
      *(undefined2 *)(param_1[0x5a9] + param_1[0x5a8] * 2) = 0;
      *(byte *)(param_1[0x5a6] + param_1[0x5a8]) = bVar4;
      param_1[0x5a8] = param_1[0x5a8] + 1;
      *(short *)(param_1 + bVar4 + 0x25) = (short)param_1[bVar4 + 0x25] + 1;
      bVar9 = param_1[0x5a8] == param_1[0x5a7] + -1;
      param_1[0x1d] = param_1[0x1d] + -1;
      param_1[0x1b] = param_1[0x1b] + 1;
    }
    else {
      bVar4 = (char)param_1[0x18] - 3;
      *(undefined2 *)(param_1[0x5a9] + param_1[0x5a8] * 2) = 1;
      *(byte *)(param_1[0x5a6] + param_1[0x5a8]) = bVar4;
      param_1[0x5a8] = param_1[0x5a8] + 1;
      *(short *)(param_1 + (byte)(&DAT_00822464)[bVar4] + 0x126) =
           (short)param_1[(byte)(&DAT_00822464)[bVar4] + 0x126] + 1;
      *(short *)(param_1 + (DAT_00822264 & 0xff) + 0x262) =
           (short)param_1[(DAT_00822264 & 0xff) + 0x262] + 1;
      bVar9 = param_1[0x5a8] == param_1[0x5a7] + -1;
      param_1[0x1d] = param_1[0x1d] - param_1[0x18];
      param_1[0x1b] = param_1[0x1b] + param_1[0x18];
      param_1[0x18] = 0;
    }
    if (bVar9) {
      iVar3 = param_1[0x17];
      if (iVar3 < 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = param_1[0xe] + iVar3;
      }
      FUN_0067f720(param_1,iVar7,param_1[0x1b] - iVar3,0);
      param_1[0x17] = param_1[0x1b];
      FUN_0067d730(*param_1);
      if (*(int *)(*param_1 + 0x10) == 0) {
        return '\0';
      }
    }
  } while( true );
}

