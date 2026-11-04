
undefined4 FUN_006c4d80(undefined4 *param_1,uint *param_2,undefined4 param_3,int param_4)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  
  iVar3 = param_1[2];
  piVar8 = (int *)*param_1;
  iVar6 = 0;
  if (0 < iVar3) {
    do {
      iVar4 = FUN_006c4d30(param_3,param_4,*piVar8);
      if (iVar4 == 0) {
        uVar7 = 0;
        cVar2 = *(char *)(*piVar8 + 1 + param_4);
        pcVar5 = (char *)(*piVar8 + 1 + param_4);
        if (cVar2 == '-') {
          uVar7 = 0xffffffff;
LAB_006c4dcb:
          pcVar5 = pcVar5 + 1;
        }
        else if (cVar2 == '+') goto LAB_006c4dcb;
        iVar4 = 0;
        cVar2 = *pcVar5;
        while ((('/' < cVar2 && (cVar2 < ':')) &&
               (iVar4 = cVar2 + -0x30 + iVar4 * 10, iVar4 <= (int)(0x7fff - uVar7)))) {
          pcVar1 = pcVar5 + 1;
          pcVar5 = pcVar5 + 1;
          cVar2 = *pcVar1;
        }
        if (*pcVar5 == '\0') {
          *param_2 = iVar4 + uVar7 ^ uVar7;
          return 0;
        }
      }
      iVar6 = iVar6 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar6 < iVar3);
  }
  return 0xffffffff;
}

