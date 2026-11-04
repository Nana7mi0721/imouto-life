
void FUN_005ee540(void)

{
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  *unaff_ESI = DAT_00a38dd8;
  unaff_ESI[1] = DAT_00a38ddc;
  FUN_0059c240(&DAT_00ddb600,3);
  if (unaff_EDI != 0) {
    FUN_0056d420(unaff_ESI + 2,&DAT_00a38d78,unaff_EDI * 4);
  }
  unaff_ESI[10] = unaff_EDI;
  return;
}

