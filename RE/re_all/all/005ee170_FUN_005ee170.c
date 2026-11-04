
uint __fastcall FUN_005ee170(undefined4 param_1,uint param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  uint in_EAX;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int local_74;
  undefined1 local_6c [16];
  int local_5c;
  int local_34;
  undefined4 local_28;
  
  iVar7 = 0;
  if ((param_3 == 0) || (local_74 = 1, param_4 != 0x20)) {
    local_74 = 0;
  }
  iVar4 = 0;
  if (1 < in_EAX) {
    do {
      iVar4 = iVar4 + 1;
    } while ((uint)(1 << ((byte)iVar4 & 0x1f)) < in_EAX);
  }
  if (1 < param_2) {
    do {
      iVar7 = iVar7 + 1;
    } while ((uint)(1 << ((byte)iVar7 & 0x1f)) < param_2);
  }
  iVar5 = 1 << ((byte)iVar4 & 0x1f);
  iVar2 = 1 << ((byte)iVar7 & 0x1f);
  if (DAT_00cc47d0 != 0) {
    puVar6 = (uint *)(&DAT_00f3a1c8 +
                     (param_5 + (iVar7 + (iVar4 + (local_74 + param_3 * 2) * 0x12) * 0x12) * 2) * 4)
    ;
    uVar3 = *puVar6;
    if ((((-1 < (int)uVar3) && ((uVar3 & 0x7c000000) == DAT_00cc47f8)) &&
        ((int)(uVar3 & 0xffff) < DAT_00cc4800)) &&
       (((piVar1 = *(int **)(DAT_00cc47d4 + (uVar3 & 0xffff) * 4), piVar1 != (int *)0x0 &&
         (*piVar1 * 0x10000 == (uVar3 & 0x3ff0000))) && (piVar1[4] == 0)))) goto LAB_005ee2f6;
  }
  FUN_00519510(local_6c,0x20,1);
  local_34 = param_3;
  if (param_3 != 0) {
    local_28 = 4;
    local_5c = param_4;
  }
  uVar3 = FUN_005243b0(local_6c,iVar5,iVar2,0,0,0,0,0);
  puVar6 = (uint *)(&DAT_00f3a1c8 +
                   (param_5 + (iVar7 + (iVar4 + (local_74 + param_3 * 2) * 0x12) * 0x12) * 2) * 4);
  *puVar6 = uVar3;
  if ((int)uVar3 < 0) {
    FUN_0056bca0(&DAT_00802600,iVar5,iVar2);
    return 0xffffffff;
  }
  FUN_00580830(uVar3,puVar6);
LAB_005ee2f6:
  return *puVar6;
}

