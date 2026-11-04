
uint __fastcall FUN_005f2200(undefined4 param_1,uint param_2,int param_3)

{
  int *piVar1;
  uint in_EAX;
  int iVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBX;
  int iVar5;
  uint *puVar6;
  int iVar7;
  undefined1 local_6c [56];
  
  iVar5 = 0;
  if (1 < in_EAX) {
    do {
      iVar5 = iVar5 + 1;
    } while ((uint)(1 << ((byte)iVar5 & 0x1f)) < in_EAX);
  }
  iVar7 = 0;
  if (1 < param_2) {
    do {
      iVar7 = iVar7 + 1;
    } while ((uint)(1 << ((byte)iVar7 & 0x1f)) < param_2);
  }
  iVar2 = 1 << ((byte)iVar5 & 0x1f);
  iVar3 = 1 << ((byte)iVar7 & 0x1f);
  if (DAT_00cc47d0 != 0) {
    puVar6 = (uint *)(&DAT_00f3cb18 +
                     (param_3 + (iVar7 + (iVar5 + unaff_EBX * 0x12) * 0x12) * 2) * 4);
    uVar4 = *puVar6;
    if ((((-1 < (int)uVar4) && ((uVar4 & 0x7c000000) == DAT_00cc47f8)) &&
        ((int)(uVar4 & 0xffff) < DAT_00cc4800)) &&
       (((piVar1 = *(int **)(DAT_00cc47d4 + (uVar4 & 0xffff) * 4), piVar1 != (int *)0x0 &&
         (*piVar1 * 0x10000 == (uVar4 & 0x3ff0000))) && (piVar1[4] == 0)))) goto LAB_005f234e;
  }
  FUN_00519510(local_6c,0x20,1);
  uVar4 = FUN_005243b0(local_6c,iVar2,iVar3,0,0,0,0,0);
  puVar6 = (uint *)(&DAT_00f3cb18 + (param_3 + (iVar7 + (iVar5 + unaff_EBX * 0x12) * 0x12) * 2) * 4)
  ;
  *puVar6 = uVar4;
  if ((int)uVar4 < 0) {
    FUN_0056bca0(&DAT_00802600,iVar2,iVar3);
    return 0xffffffff;
  }
  FUN_00580830(uVar4,puVar6);
LAB_005f234e:
  return *puVar6;
}

