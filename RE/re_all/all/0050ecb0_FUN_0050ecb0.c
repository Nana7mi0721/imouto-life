
HRGN FUN_0050ecb0(int param_1,int param_2,int *param_3,int *param_4,int param_5)

{
  HRGN hrgnDst;
  HRGN pHVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  bool bVar6;
  int local_c;
  int local_8;
  int local_4;
  
  bVar6 = false;
  FUN_005167a0(&local_8,&local_c);
  pcVar5 = CreateRectRgn_exref;
  hrgnDst = CreateRectRgn(0,0,local_8,local_c);
  pHVar1 = CreateRectRgn(0,0,local_8,local_c);
  CombineRgn(hrgnDst,hrgnDst,pHVar1,3);
  DeleteObject(pHVar1);
  local_4 = (int)param_4 - param_1 * param_5;
  iVar3 = 0;
  if (0 < param_2) {
    do {
      iVar4 = 0;
      iVar2 = -1;
      param_4 = param_3;
      if (0 < param_1) {
        do {
          switch(param_5) {
          case 1:
            bVar6 = (char)*param_4 == '\0';
            break;
          case 2:
            bVar6 = (short)*param_4 == 0;
            break;
          case 3:
            if (((short)*param_4 == 0) || (*(char *)((int)param_4 + 2) == '\0')) {
              bVar6 = true;
              goto LAB_0050ed8e;
            }
            bVar6 = false;
            goto LAB_0050ee2d;
          case 4:
            bVar6 = *param_4 == 0;
          }
          if (bVar6) {
LAB_0050ed8e:
            if (iVar2 != -1) {
              pHVar1 = (HRGN)(*pcVar5)(iVar2,iVar3,iVar4,iVar3 + 1);
              CombineRgn(hrgnDst,hrgnDst,pHVar1,2);
              DeleteObject(pHVar1);
              iVar2 = -1;
              pcVar5 = CreateRectRgn_exref;
            }
          }
          else {
LAB_0050ee2d:
            if (iVar2 == -1) {
              iVar2 = iVar4;
            }
          }
          param_3 = (int *)((int)param_4 + param_5);
          iVar4 = iVar4 + 1;
          param_4 = param_3;
        } while (iVar4 < param_1);
        if (iVar2 != -1) {
          pHVar1 = (HRGN)(*pcVar5)(iVar2,iVar3,iVar4,iVar3 + 1);
          CombineRgn(hrgnDst,hrgnDst,pHVar1,2);
          DeleteObject(pHVar1);
        }
      }
      param_3 = (int *)((int)param_3 + local_4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_2);
  }
  return hrgnDst;
}

