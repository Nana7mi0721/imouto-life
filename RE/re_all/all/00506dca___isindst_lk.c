
/* Library Function - Single Match
    __isindst_lk
   
   Library: Visual Studio 2003 Release */

bool __isindst_lk(void)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int *unaff_EBX;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  
  if (DAT_0084be74 == 0) {
    return false;
  }
  iVar1 = unaff_EBX[5];
  if ((iVar1 != DAT_0084bf08) || (iVar1 != DAT_0084bf14)) {
    if (DAT_00a1fef4 == 0) {
      cvtdate(1,1,iVar1,1,0,0,0,0,0);
      cvtdate(0,1,iVar1,5,0,0,0,0,0);
    }
    else {
      if (DAT_00a1fee0 != 0) {
        uVar5 = 0;
        uVar4 = 0;
        uVar6 = DAT_00a1fee6;
      }
      else {
        uVar5 = DAT_00a1fee4;
        uVar4 = DAT_00a1fee6;
        uVar6 = 0;
      }
      cvtdate(1,DAT_00a1fee0 == 0,iVar1,uVar4,uVar5,uVar6,DAT_00a1feea,DAT_00a1feec,DAT_00a1feee);
      if (DAT_00a1fe8c != 0) {
        uVar5 = 0;
        uVar4 = 0;
        uVar6 = DAT_00a1fe92;
      }
      else {
        uVar5 = DAT_00a1fe90;
        uVar4 = DAT_00a1fe92;
        uVar6 = 0;
      }
      cvtdate(0,DAT_00a1fe8c == 0,iVar1,uVar4,uVar5,uVar6,DAT_00a1fe96,DAT_00a1fe98,DAT_00a1fe9a);
    }
  }
  iVar1 = unaff_EBX[7];
  if (DAT_0084bf0c < DAT_0084bf18) {
    if ((iVar1 < DAT_0084bf0c) || (DAT_0084bf18 < iVar1)) {
      return false;
    }
    if ((iVar1 <= DAT_0084bf0c) || (DAT_0084bf18 <= iVar1)) {
LAB_00506f1d:
      iVar3 = ((unaff_EBX[2] * 0x3c + unaff_EBX[1]) * 0x3c + *unaff_EBX) * 1000;
      if (iVar1 == DAT_0084bf0c) {
        bVar2 = DAT_0084bf10 <= iVar3;
      }
      else {
        bVar2 = iVar3 < DAT_0084bf1c;
      }
      return bVar2;
    }
  }
  else if ((DAT_0084bf18 <= iVar1) && (iVar1 <= DAT_0084bf0c)) {
    if ((DAT_0084bf18 < iVar1) && (iVar1 < DAT_0084bf0c)) {
      return false;
    }
    goto LAB_00506f1d;
  }
  return true;
}

