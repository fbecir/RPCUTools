//-----------------------------------------------------------------------------
//								XGeoPref.h
//								==========
//
// Auteur : F.Becirspahic - Projet Camera Numerique
//
// 04/09/2007
//-----------------------------------------------------------------------------

#ifndef _XGEOPREF_H
#define _XGEOPREF_H

#include "XLambert.h"
#include "XDomGeod.h"
#include "XNCGeod.h"
#include "XWebMercator.h"

class XGeoPref {
protected:
	// Preferences geodesiques
  static XLambert								m_Lambert;		// Moteur de reprojection France Metropolitaine
  static XDomGeod								m_DomGeod;		// Moteur de reprojection DOM
  static XNCGeod                m_NCGeod;     // Moteur de reprojection Nouvelle Caledonie
  static XWebMercator           m_WebMercator;// Moteur de reprojection WebMercator
  static XProjCode							m_Projection;	// Projection par defaut
  static XProjCode							m_ProjecView;	// Projection affichee

  // Preferences pour les sites geographiques
  static byte       m_nGoogleMode;
  static byte       m_nVEMode;
  static byte       m_nGeoportMode;
  static bool       m_bAutoSynchro;
  static bool       m_bCadastre;
  static bool       m_bGeorefTfw;
  static bool       m_bGeorefTab;
  static bool       m_bGeorefGxt;
  static bool       m_bGeorefXml;
  static bool       m_bGeorefGrf;

public:
	XGeoPref() {;}
	virtual ~XGeoPref() {;}

	// Preferences geodesiques
	bool InitProjection(const char* gridfile, XProjCode projection);
	inline XProjCode Projection() { return m_Projection;}
	void Projection(XProjCode proj) { m_Projection = proj;}
  inline XProjCode ProjecView() { return m_ProjecView;}
  void ProjecView(XProjCode proj) { m_ProjecView = proj;}

  bool Convert(XProjCode start_proj, XProjCode end_proj, double Xi, double Yi,
               double& Xf, double& Yf, double Z = 0.);
  bool ConvertDeg(XProjCode start_proj, XProjCode end_proj, double Xi, double Yi,
                  double& Xf, double& Yf, double Z = 0.);
  double AltLin(XProjCode start_proj, double Xi, double Yi);

  // Preferences Internet
  inline uint16 GoogleMode() { return m_nGoogleMode;}
  void GoogleMode(byte mode) { m_nGoogleMode = mode;}
  inline uint16 VEMode() { return m_nVEMode;}
  void VEMode(byte mode) { m_nVEMode = mode;}
  inline uint16 GeoportMode() { return m_nGeoportMode;}
  void GeoportMode(byte mode) { m_nGeoportMode = mode;}
  inline bool AutoSynchro() { return m_bAutoSynchro;}
  void AutoSynchro(bool flag) { m_bAutoSynchro = flag;}
  inline bool Cadastre() { return m_bCadastre;}
  void Cadastre(bool flag) { m_bCadastre = flag;}

  // Preferences geo-referencement
  inline bool GeorefTfw() { return m_bGeorefTfw;}
  void GeorefTfw(bool flag) { m_bGeorefTfw = flag;}
  inline bool GeorefTab() { return m_bGeorefTab;}
  void GeorefTab(bool flag) { m_bGeorefTab = flag;}
  inline bool GeorefGxt() { return m_bGeorefGxt;}
  void GeorefGxt(bool flag) { m_bGeorefGxt = flag;}
  inline bool GeorefXml() { return m_bGeorefXml;}
  void GeorefXml(bool flag) { m_bGeorefXml = flag;}
  inline bool GeorefGrf() { return m_bGeorefGrf;}
  void GeorefGrf(bool flag) { m_bGeorefGrf = flag;}

};

#endif // _XGEOPREF_H
