
void FUN_00678520(int param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  byte bVar6;
  
  pbVar4 = param_2;
  if ((param_3 & 2) == 0) {
    bVar6 = param_2[3];
    if ((bVar6 == 0) || (*(byte *)(param_1 + 0x159) < bVar6)) goto LAB_006785cd;
    param_2 = (byte *)CONCAT31(param_2._1_3_,bVar6);
    iVar5 = 1;
  }
  else {
    bVar6 = 8;
    if (param_3 != 3) {
      bVar6 = *(byte *)(param_1 + 0x159);
    }
    bVar1 = *param_2;
    if (((((bVar1 == 0) || (bVar6 < bVar1)) || (bVar2 = param_2[1], bVar2 == 0)) ||
        ((bVar6 < bVar2 || (bVar3 = param_2[2], bVar3 == 0)))) || (bVar6 < bVar3))
    goto LAB_006785cd;
    param_2 = (byte *)CONCAT31(CONCAT12(param_2._3_1_,CONCAT11(bVar3,bVar2)),bVar1);
    iVar5 = 3;
  }
  if ((param_3 & 4) != 0) {
    bVar6 = pbVar4[4];
    if ((bVar6 == 0) || (*(byte *)(param_1 + 0x159) < bVar6)) {
LAB_006785cd:
      FUN_006687b0(param_1,s_Invalid_sBIT_depth_specified_00a0d62c);
      return;
    }
    *(byte *)((int)&param_2 + iVar5) = bVar6;
    iVar5 = iVar5 + 1;
  }
  FUN_00677430(param_1,0x73424954,&param_2,iVar5);
  return;
}

