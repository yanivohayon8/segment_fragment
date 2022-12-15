#pragma once	
#include <igl/adjacency_list.h>
#include <set>
#include <Fragment.h>


class Segment: public ObjFragment
{
public:
	Segment();

	std::vector<int> piece_vertices_index_;
	std::vector<int> m_OutsideBoundaryVertsIndexes;
	double m_fracSizeOfFragment;
	double m_AvgCurvedness;
	std::string m_ParentFilePath;

	Segment(std::vector<int> piece_vertices_index, std::vector<int> piece_vertices_indexes_boundary);

	Segment(Eigen::MatrixXd V, Eigen::MatrixXd  TC, Eigen::MatrixXd N,
		Eigen::MatrixXi F, Eigen::MatrixXi  FTC, Eigen::MatrixXi FN);

	//Eigen::MatrixXd m_Vertices;//   V  double matrix of vertex positions  #V by 3
	//Eigen::MatrixXd m_TextureCoordinates;//   TC  double matrix of texture coordinats #TC by 2
	//Eigen::MatrixXd m_Normals;//   N  double matrix of corner normals #N by 3
	//Eigen::MatrixXi m_Faces;//   F  #F list of face indices into vertex positions
	//Eigen::MatrixXi m_Faces2TextureCoordinates;//   FTC  #F list of face indices into vertex texture coordinates
	//Eigen::MatrixXi m_Faces2Normals;//   FN  #F list of face indices into vertex normals
	//Eigen::MatrixXd m_Colors;


	// send the parameters as const ? 
	void loadBasicData(const std::vector <std::vector<int>>& parentVerticesAdjacentFacesList,
		const Eigen::MatrixXi& parentFaces, const Eigen::MatrixXd& parentVertices,
		const Eigen::MatrixXi& parentFaces2TextureCoordinates,
		const Eigen::MatrixXi& parentFaces2Normals, const Eigen::MatrixXd& parentNormals, std::string fragFilePath);

	double calcAvgCurvedness();
	void saveAsObj(std::string outputPath, const Eigen::MatrixXd parentNormals, const Eigen::MatrixXd& parentTextureCoordinates);


};